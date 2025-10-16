// minishell/
// ├── includes/
// │   ├── minishell.h
// │   ├── lexer.h
// │   ├── parser.h
// │   ├── exec.h
// │   ├── builtins.h
// │   ├── env.h
// │   ├── utils.h
// │   └── signals.h
// │
// ├── src/
// │   ├── main.c
// │
// │   ├── lexer/
// │   │   ├── lexer.c
// │   │   └── lexer_utils.c
// │
// │   ├── parser/
// │   │   ├── parser.c
// │   │   └── parser_utils.c
// │
// │   ├── exec/
// │   │   ├── exec.c
// │   │   ├── pipex.c
// │   │   ├── redirections.c
// │   │   └── heredoc.c
// │
// │   ├── builtins/
// │   │   ├── cd.c 
// │   │   ├── echo.c || just out
// │   │   ├── env.c || just out
// │   │   ├── exit.c
// │   │   ├── export.c || just out
// │   │   └── unset.c
// │
// │   ├── env/
// │   │   ├── env_utils.c
// │   │   └── expansion.c
// │
// │   ├── signals/
// │   │   ├── signals.c
// │   │   └── signals_utils.c
// │
// │   └── utils/
// │       ├── error.c
// │       ├── memory.c
// │       └── str_utils.c
// │
// ├── libft/ (if needed)
// ├── Makefile
// ├── README.md
// └── .gitignore

//            [>]
//     /             \
//    [<<]             file1
//    /   \
//  heredoc  ls-la


// cat << EOF | grep -i hello | wc -l > result.txt



//precedence
//* 1: ';'                 → Command separator
// * 2: '||'                → Logical OR
// * 3: '&&'                → Logical AND
// * 4: '|'                 → Pipe
// * 5: '<' '>' '>>' '<<'   → Redirections
// * 6: command/words       → Simple commands
// * 7: '()'                → Subshell (highest grouping power)

/*                         Abstract Syntax Tree (AST) Schema
---------------------------------------------------------------------------------------
                                     [ > ]
                                    /     \
                              [ PIPE ]    "result.txt"
                             /       \
                     [ PIPE ]         "wc -l"
                    /       \
            [ HEREDOC ]    "grep -i hello"
             /        \
           "cat"       "EOF"             
*/

// cmd1 > file1 || cmd2 > file2
/*                                     [ > ]
                                    /     \
                              [ PIPE ]    "result.txt"
                             /       \
                     [ PIPE ]         "wc -l"
                    /       \
            [ HEREDOC ]    "grep -i hello"
             /        \
           "cat"       "EOF"   */

// Operator precedence table (from lowest to highest):
// 1: ';'                 → Command separator
// 2: '||'                → Logical OR
// 3: '&&'                → Logical AND
// 4: '|'                 → Pipe
// 5: '<' '>' '>>' '<<'   → Redirections
// 6: command/words       → Simple commands
// 7: '()'                → Subshell (highest grouping power)

// Notes:
// - '$' and '*' are token-level expansions, handled before parsing


// The shell will work only in interactive mode (no scripts, i.e. the executable takes no arguments)
// Run simple commands with absolute, relative path (e.g. /bin/ls, ../bin/ls)
// Run simple commands without a path (e.g. ls, cat, grep, etc…)
// Have a working history (you can navigate through commands with up/down arrows)
// Implement pipes (|)
// Implement redirections (<, >, >>)
// Implement the here-doc (<<)
// Handle double quotes ("") and single quotes (''), which should escape special characters, beside $ for double quotes.
// Handle environment variables ($ followed by a sequence of characters).
// Handle signals like in bash (ctrl + C, ctrl + \, ctrl + D).
// Implement the following built-ins:
// — echo (option -n only)
// — exit
// — env (with no options or arguments)
// — export (with no options)
// — unset (with no options)
// — cd
// — pwd
// And for the bonus part (optional, but i did it, because it’s cool!)
// — handle && and || with the parenthesis () for priority.
// — handle * wildcards for the current working directory.
/*
 Common exit status values
#define EXIT_SUCCESS 0
#define EXIT_GENERAL_ERROR 1
#define EXIT_MISUSE_BUILTIN 2
#define EXIT_CANNOT_EXECUTE 126
#define EXIT_COMMAND_NOT_FOUND 127
#define EXIT_INVALID_EXIT_ARG 128
// 128+n = terminated by signal n
*/
// #include "includes/lexer.h"
// #include "includes/minishell.h"
// #include "includes/parsing.h"

// int main ()
// {
//         t_ast tree;

//         tree.full_cmd = NULL;
//         tree.type = PIPE;
        
//         t_ast l;

//         l.type = PIPE;
//         l.full_cmd = NULL;

//         t_ast ll;

//         ll.type = COMMAND;
//         char *args[] = {"cmd1",NULL};

//         ll.full_cmd->args = args;
//         ll.full_cmd->red_in = NULL;
//         ll.full_cmd->red_out = NULL;
//         ll.left = NULL;
//         ll.right = NULL;

//         t_ast lr;

//         lr.type = COMMAND;
//         char *args2[] = {"cmd2",NULL};

//         lr.full_cmd->args = args2;
//         lr.full_cmd->red_in = NULL;
//         lr.full_cmd->red_out = NULL;
//         lr.left = NULL;
//         lr.right = NULL;

//         t_ast r;

//         r.type = COMMAND;
//         char *args3[] = {"cmd2",NULL};

//         r.full_cmd->args = args3;
//         r.full_cmd->red_in = NULL;
//         r.full_cmd->red_out = NULL;
//         r.left = NULL;
//         r.right = NULL;



//         l.left = &ll;
//         l.right = &lr;

//         tree.left = &l;
//         tree.right = &r;

        /*    [pipe]
              / \
        [pipe]  [cmd3]
        /   \
  [cmd1]     [cmd2]
        */

      /*    [tree]
            /   \
          [l]  [r]
        /  \
     [ll]  [lr]
        */
// }


/*
---

### **Key Rules:**  
1. **Parentheses `( )`**  
- Highest precedence → **deepest in AST** (forces a subtree).  
- Example: `(cmd1 | cmd2) && cmd3` → `|` is evaluated first inside `( )`.  

2. **Redirections (`>`, `<`, `>>`, `<<`)**  
- Bind tightly to commands → **appear near leaves**.  
- Example: `cmd1 > file | cmd2` → `>` binds to `cmd1` before `|`.  

3. **Pipes (`|`)**  
- Lower precedence → **higher in AST** than redirections.  

4. **Logical Operators (`&&`, `||`)**  
- Even lower → **closer to the root**.  

5. **Semicolon (`;`)**  
- Lowest precedence → **root of the AST** (if present).  

---

### **Execution Order vs. AST Depth**  
- **Higher in AST (root) = evaluated last** (loose binding).  
- **Lower in AST (leaves) = evaluated first** (tight binding).  

---

### **Summary Table**  
| Operator      | Precedence | AST Depth | Example Binding          |
|--------------|------------|-----------|--------------------------|
| `( )`        | Highest    | Deepest   | `(cmd1 && cmd2)`         |
| `>`, `>>`, etc. | High     | Low       | `cmd1 > file`            |
| `|`          | Medium     | Middle    | `cmd1 | cmd2`            |
| `&&`         | Low        | High      | `cmd1 && cmd2`           |
| `||`         | Lower      | Higher    | `cmd1 || cmd2`           |
| `;`          | Lowest     | Root      | `cmd1; cmd2`             |

---

### **Pseudocode for AST Building**  
```c
// Parse by precedence (lowest to highest)
ASTNode *parse() {
 return parse_semicolon();  // Lowest precedence = root
}

ASTNode *parse_semicolon() {
 ASTNode *node = parse_logical_or();
 while (current_token == ";") {
     consume(";");
     node = new_node(";", node, parse_logical_or());
 }
 return node;
}

ASTNode *parse_logical_or() {
 ASTNode *node = parse_logical_and();
 while (current_token == "||") {
     consume("||");
     node = new_node("||", node, parse_logical_and());
 }
 return node;
}

// ... repeat for `&&`, `|`, redirections, and finally `( )` ...*/


//