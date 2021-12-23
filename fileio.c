#include "fileio.h"
#define BUF_SIZE 2048

void writeFile(char* file, char* data){
    FILE* fp = fopen(file, "r+");
    fprintf(fp, "%s", data);
    fclose(fp);
}

// Copy pasted read line from file and return as char*
char *readFile(char* path, int line_no )
{
    FILE *f = fopen(path, "r+");
    char   buf[ BUF_SIZE ];
    size_t curr_alloc = BUF_SIZE, curr_ofs = 0;
    char   *line      = malloc( BUF_SIZE );
    int    in_line    = line_no == 1;
    size_t bytes_read;
 
    /* Illegal to ask for a line before the first one. */
    if ( line_no < 1 )
        return NULL;
 
    /* Handle out-of-memory by returning NULL */
    if ( !line )
        return NULL;
 
    /* Scan the file looking for newlines */
    while ( line_no && 
            ( bytes_read = fread( buf, 1, BUF_SIZE, f ) ) > 0 )
    {
        int i;
 
        for ( i = 0 ; i < bytes_read ; i++ )
        {
            if ( in_line )
            {
                if ( curr_ofs >= curr_alloc )
                {
                    curr_alloc <<= 1;
                    line = realloc( line, curr_alloc );
 
                    if ( !line )    /* out of memory? */
                        return NULL;
                }
                line[ curr_ofs++ ] = buf[i];
            }
 
            if ( buf[i] == '\n' )
            {
                line_no--;
 
                if ( line_no == 1 )
                    in_line = 1;
 
                if ( line_no == 0 )
                    break;
            }
        }
    }
 
    /* Didn't find the line? */
    if ( line_no != 0 ) 
    {
        free( line );
        return NULL;
    }
 
    /* Resize allocated buffer to what's exactly needed by the string 
       and the terminating NUL character.  Note that this code *keeps*
       the terminating newline as part of the string. 
     */
    line = realloc( line, curr_ofs + 1 );
 
    if ( !line ) /* out of memory? */
        return NULL;
 
    /* Add the terminating NUL. */
    line[ curr_ofs ] = '\0';
 
    /* Return the line.  Caller is responsible for freeing it. */
    return line;
}