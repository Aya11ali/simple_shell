#include "shell.h"
char *_getpath(char *command)
{
    char *path_env, *fullcom, *dir;
    struct stat st;
    int i;
    
    for (i=0; command[i]; i++)
    {
        if (command[i] == '/')
        {
            if (stat(command, &st) == 0)
                return(_strdup(command));
            return (NULL);    
        }
        
    }
    
    path_env = _getenv("PATH");
    if (!path_env)
        return (NULL);
        
    dir= strtok(path_env, ":");
    while(dir)
    {
        fullcom = malloc(_strlen(dir) + _strlen(command) + 2);
        if(fullcom)
        {
            _strcpy(fullcom, dir);
            _strcat(fullcom, "/");
            _strcat(fullcom, command);
            if(stat(fullcom, &st) == 0)
            {
                free(path_env);
                return (fullcom);
            }
            free(fullcom); fullcom = NULL;
            
            dir = strtok(NULL, ":");
            
        }
    }
    free(path_env);
    return (NULL);
    
}
