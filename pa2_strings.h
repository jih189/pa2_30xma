/*
 * Filename: pa2_strings.h
 * Author: Liu Tan
 * Userid: cs30xma
 * Description: Strings used in PA2 output
 */

#define STR_USAGE "\nUsage: %s passPhrase key1 key2 rotVal FILE\n"\
       "    passPhrase  (must at least eight characters long)\n"\
       "    key1        (must be numeric; decimal, octal or hexadecimal)\n"\
       "    key2        (must be numeric; decimal, octal or hexadecimal)\n"\
       "    rotVal      (must be a decimal value within the range [%d - %d])\n"\
       "    FILE        (must be the name of a file or '-' for stdin)\n\n"

#define STR_ERR_BAD_PASSPHRASE "\n\tPassphrase must be at least %d chars long\n"

#define STR_ERR_BAD_ROT "\n\tRotation key must be within the range of "\
                             "[%d <-> %d]\n"

#define STR_ERR_CONVERTING "\n\tConverting \"%s\" base \"%d\""

#define STR_ERR_NOTINT "\n\t\"%s\" is not an integer\n"

#define STR_ERR_NUM_ERRORS "\n\t--- Found %d errors. ---\n\n"

#define STR_ERR_BAD_FILE "\n\t%s"
