let help = fun
 | [] => "Commands:
help
calc
banana"
 | ["help", ..._] => "
!**help**:
Shows information on available commands.

``!help [command]``
``[command]`` *(optional)*: the name of a command"
 | ["calc", ..._] => "
!**calc!**:
Performs a math calculation on two numbers.

``!calc <numberA> <operator> <numberB>``

``<numberA>``: a valid integer or decimal number
``<operator>``: a maths operator (``+``, ``-``, ``*``, ``/``)
``<numberB>``: a valid integer or decimal number"
 | _ => "I don't know how to help with that"
