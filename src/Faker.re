[@bs.module "faker"] external _fake: string => string = "fake";
let fake = input =>
  switch (_fake(input)) {
  | value => Belt.Result.Ok(value)
  | exception (Js.Exn.Error(x)) => Belt.Result.Error(x)
  };
