let nullable = Faker.nullable;

[@bs.deriving abstract]
type t = {past: (Js.Nullable.t(int), Js.Nullable.t(Js.Date.t)) => Js.Date.t};
[@bs.module "faker"] external fakers : t = "date";
let past = (~years=?, ~refDate=?, ()) =>
  past(fakers, nullable(years), nullable(refDate));
