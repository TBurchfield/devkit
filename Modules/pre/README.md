# Pre

A tool for bootstrapping code

# Usage

```
pre [filename] <flag_values>

EXAMPLE:
pre -d /path/to/config/dir sample_file FLAG1=foo FLAG2=bar

OPTIONAL FLAGS:
-d    config directory    defaults to ~/.config/pre/
```

pre files are stored in a config directory. These files contain instructions
that can be used to build a project.


# PRE INSTRUCTION STANDARDS:

All template variables are replaced via what is essentially sed, don't replicate
strings in your template names

Instruction | Usage | Definition
---|---|---
DIR | DIR <list of children> | Dir creates a directory that will contain all of the files/directories listed
FILE | FILE <file contents> | File writes the contents of a file, templating in variable values file contents is either a string or a file() specifier (the contents of the file a copied directly and then templated)


