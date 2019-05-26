let safelyCalculate = (left, op, right) => {
  let fLeft = Js.Float.fromString(left);
  let fRight = Js.Float.fromString(right);
  (
    switch (op) {
    | "+" => fLeft +. fRight
    | "-" => fLeft -. fRight
    | "*" => fLeft *. fRight
    | "/" => fLeft /. fRight
    | _ => raise(Failure("Unknown operator " ++ op))
    }
  )
  ->Js.Float.toString;
};

let rec calculate =
  fun
  | [] => "Error: No operations"
  | ops when List.length(ops) mod 2 == 0 => "ERROR: argument mismatch"
  | [left, op, right, ...rest] => {
      switch (safelyCalculate(left, op, right), rest) {
      | (result, []) => result
      | (result, more) => calculate([result, ...more])
      | exception (Failure("float_of_string")) => "Parse error in calculation argument"
      | exception (Failure(a)) => a
      };
    }
  | mismatch => "Unhandled calcuation: " ++ String.concat("", mismatch);