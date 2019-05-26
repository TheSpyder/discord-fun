let help = fun
 | [] => "Commands:
help
calc
banana"
 | ["help", ..._] => "
!**help**:\n
Shows information on available commands.\n
\n
``!help [command]``\n
\n
``[command]`` *(optional)*: the name of a command"
 | ["calc", ..._] => "Gimme a minute!"
 | _ => "I don't know how to help with that"
