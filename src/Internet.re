let nullable = Faker.nullable;

[@bs.deriving abstract]
type t = {userName: (Js.Nullable.t(string), Js.Nullable.t(string)) => string};
[@bs.module "faker"] external fakers : t = "internet";
let userName = (~firstName=?, ~lastName=?, ()) =>
  userName(fakers, nullable(firstName), nullable(lastName));
