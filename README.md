Shellby - A Simple Shell 
Shellby is a minimalist UNIX command interpreter, developed as a component of the low-level programming and algorithm track at ALX.
Description 
Shellby serves as a straightforward UNIX command language interpreter. It parses commands from either a file or standard input and executes them accordingly.
Intro: 
To invoke Shellby, follow these steps:
Compile all .c files within the repository:
Copy code
gcc *.c -o shellby 
Run the resulting executable:
bashCopy code
./shellby 
Shellby supports both interactive and non-interactive modes:
In non-interactive mode, it processes commands from standard input that aren't connected to a terminal.
Example:
bashCopy code
$ echo "echo 'hello'" | ./shellby 'hello' 
In interactive mode, it displays the prompt $ when ready to accept a command.
Example:
shellCopy code
$ ./shellby $ 
Alternatively, if command line arguments are provided, Shellby treats the first argument as a file containing commands to execute.
Example:
bashCopy code
$ cat test echo 'hello' $ ./shellby test 'hello' 
Env
Shellby inherits and copies the environment of its parent process upon invocation. Key environmental variables include:
PWD: The current working directory.
OLDPWD: The previous working directory.
HOME: The user's home directory.
PATH: A list of directories where Shellby searches for commands.
excution 
Upon receiving a command, Shellby tokenizes it into words using spaces as delimiters. It considers the first word as the command and the rest as its arguments. Shellby performs the following actions:
If the command is a built-in, it executes it.
If the command is found in the PATH, Shellby executes it with any remaining arguments in a separate environment.
Exit Status 
Shellby returns the exit status of the last executed command, where zero indicates success and non-zero indicates failure. For example:
shellCopy code
$ echo "echo $PWD" | ./shellby /home/vagrant/holberton/simple_shell $? 0 

VarReplacement
Shellby interprets the $ character for variable replacement. For example:
$ENV_VARIABLE is substituted with its value.
$? represents the return value of the last executed program.
$$ represents the current process ID.
Comments 
Shellby ignores lines starting with #, treating them as comments.

Operators 
Shellby recognizes special operators:
;: Separates and executes commands sequentially.
&&: Executes the second command only if the first returns a zero exit status.
||: Executes the second command only if the first returns a non-zero exit status.
Shellby Builtin Commands 
Shellby includes several built-in commands, including cd, alias, exit, env, setenv, and unsetenv. Each command is accompanied by a usage description.
Authors 
Contributors to the Repository:

1. Kidus Daniel
   - Email: kidusdaniel576@gmail.com

2. Abbie Njoki
   - Email: abigailnjoki001@gmail.com

