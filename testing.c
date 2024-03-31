#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <libgen.h>

#define TRUE 1
#define FALSE 0

char *repo_find(char *path, int required);
int isDirExists(const char *path);

int main(int argc, char **argv)
{
    char *filename;
    filename = repo_find(argv[1], TRUE);
    printf("%s\n", filename);
}

char *repo_find(char *path, int required)
/*Use "." for path if you want relative path*/
{
    char *fullpath, *gitpath, *parent;
    fullpath = realpath(path, NULL);
    gitpath = malloc(strlen(path) + 5);
    strcpy(gitpath, path);
    strcat(gitpath, "/git");
    if (isDirExists(gitpath))
        return fullpath;
    else
    {
        parent = dirname(strdup(fullpath));
    }

    if (parent == fullpath)
    {
        if (required)
        {
            printf("No git directory");
            exit(EXIT_FAILURE);
        }
        /*May need to raise exception or whatever*/
        else
            return NULL;
    }

    return repo_find(parent, required);
}

int isDirExists(const char *path)
{
    struct stat stats;
    stat(path, &stats);

    if (S_ISDIR(stats.st_mode))
        return TRUE;

    return FALSE;
}
