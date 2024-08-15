#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

const char *pre = "#include <stdlib.h>\n\n"
                  "int %s(int comb) {\n"
                  "    switch(comb) {\n";

const char *cases = "        case 0b%s: return 0x%s;\n";

const char *post = "        default: return 0;\n"
                   "    }\n}";

int main(int argc, char const *argv[])
{
    FILE *configFd, *keymapFd;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    char *fnName = argc > 1 ? argv[1] : "getUsageId";
    char *configFile = argc > 2 ? argv[2] : "alphabets";
    char *keymapHeaderFile = argc > 3 ? argv[3] : "keymap.h";

    configFd = fopen(configFile, "r");

    if (configFd == NULL)
    {
        printf("No such file '%s'\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    keymapFd = fopen(keymapHeaderFile, "w");

    fprintf(keymapFd, pre, fnName);

    while ((read = getline(&line, &len, configFd)) != -1)
    {
        printf("%s", line);

        char buttonCombination[7], usageId[3];
        sscanf(line, "%[^=]=%s", buttonCombination, usageId);
        printf("Comb = %s, Id = %s\n", buttonCombination, usageId);

        fprintf(keymapFd, cases, buttonCombination, usageId);
    }

    fprintf(keymapFd, post);

    fclose(configFd);
    if (line)
        free(line);

    exit(EXIT_SUCCESS);
}
