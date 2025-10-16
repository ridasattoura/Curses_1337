#include "minishell.h"

char *token_type_str(t_token_type type)
{
    if (type == COMMAND) return "COMMAND";
    if (type == PIPE) return "PIPE";
    if (type == REDIRECT_IN) return "REDIRECT_IN";
    if (type == REDIRECT_OUT) return "REDIRECT_OUT";
    if (type == APPEND) return "APPEND";
    if (type == HEREDOC) return "HEREDOC";
    if (type == EXPAND_HERE_DOC) return "EXPAND_HERE_DOC";
    if (type == AND) return "AND";
    if (type == OR) return "OR";
    if (type == parenthesis_open) return "(";
    if (type == parenthesis_close) return ")";
    return "UNKNOWN";
}

// void print_tokens(t_token *token_list, const char *label, const char *color, const char *prefix)
// {
//     if (!token_list)
//         return;

//     printf("%s    %s%s: ", prefix, color, label);
//     while (token_list)
//     {
//         printf("[%s] ", token_list->value);
//         token_list = token_list->next;
//     }
//     printf(RESET "\n");
// }

// void draw_ast_vertical(t_ast *node, const char *prefix, int is_left)
// {
//     if (!node)
//         return;

//     // ├── or └──
//     printf("%s%s── ", prefix, is_left ? "├" : "└");

//     // Choose color
//     const char *color;
//     if (node->type == COMMAND)
//         color = GREEN;
//     else if (node->type == REDIRECT_IN || node->type == REDIRECT_OUT ||
//              node->type == APPEND || node->type == HEREDOC)
//         color = BLUE;
//     else if (node->type == PIPE || node->type == AND || node->type == OR)
//         color = YELLOW;
//     else
//         color = CYAN;

//     // Print node type
//     printf("%s%s%s\n", color, token_type_str(node->type), RESET);

//     // Print COMMAND details
//     if (node->type == COMMAND && node->full_cmd)
//     {
//         // Print arguments
//         if (node->full_cmd->args)
//             print_tokens(node->full_cmd->args, "ARGS", GREEN, prefix);

//         // Print redirections (in and out)
//         if (node->full_cmd->red_in)
//             print_tokens(node->full_cmd->red_in, "REDIR_IN", BLUE, prefix);
//         if (node->full_cmd->red_out)
//             print_tokens(node->full_cmd->red_out, "REDIR_OUT", BLUE, prefix);
//     }

//     // Prepare new prefix for children
//     char new_prefix[256];
//     snprintf(new_prefix, sizeof(new_prefix), "%s%s", prefix, is_left ? "│   " : "    ");

//     // Recurse: left first (conventionally), then right
//     if (node->left || node->right)
//     {
//         if (node->left)
//             draw_ast_vertical(node->left, new_prefix, 1);
//         if (node->right)
//             draw_ast_vertical(node->right, new_prefix, 0);
//     }
// }

// // Root node is special: no prefix, just print it
// void print_ast_topdown(t_ast *root)
// {
//     if (!root)
//         return;

//     // Root line
//     const char *color;
//     if (root->type == COMMAND)
//         color = GREEN;
//     else if (root->type == REDIRECT_IN || root->type == REDIRECT_OUT ||
//              root->type == APPEND || root->type == HEREDOC)
//         color = BLUE;
//     else if (root->type == PIPE || root->type == AND || root->type == OR)
//         color = YELLOW;
//     else
//         color = CYAN;

//     printf("%s%s%s\n", color, token_type_str(root->type), RESET);

//     // Print root CMD details if any
//     if (root->type == COMMAND && root->full_cmd)
//     {
//         if (root->full_cmd->args)
//             print_tokens(root->full_cmd->args, "ARGS", GREEN, "");
//         if (root->full_cmd->red_in)
//             print_tokens(root->full_cmd->red_in, "REDIR_IN", BLUE, "");
//         if (root->full_cmd->red_out)
//             print_tokens(root->full_cmd->red_out, "REDIR_OUT", BLUE, "");
//     }

//     // Then recurse
//     if (root->left)
//         draw_ast_vertical(root->left, "", 1);
//     if (root->right)
//         draw_ast_vertical(root->right, "", 0);
// }
