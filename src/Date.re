let nullable = Faker.nullable;

type dateOption = {
  .
  "abbr": bool,
  "context": bool,
};

[@bs.deriving abstract]
type t = {
  past: (Js.Nullable.t(int), Js.Nullable.t(Js.Date.t)) => Js.Date.t,
  future: (Js.Nullable.t(int), Js.Nullable.t(Js.Date.t)) => Js.Date.t,
  between: (Js.Date.t, Js.Date.t) => Js.Date.t,
  recent: Js.Nullable.t(int) => Js.Date.t,
  month: Js.Nullable.t(dateOption) => string,
  weekday: Js.Nullable.t(dateOption) => string,
};
[@bs.module "faker"] external fakers : t = "date";
let past = (~years=?, ~refDate=?, ()) =>
  past(fakers, nullable(years), nullable(refDate));
let future = (~years=?, ~refDate=?, ()) =>
  future(fakers, nullable(years), nullable(refDate));
let between = (from, to_) => between(fakers, from, to_);
let recent = (~days=?, ()) => recent(fakers, nullable(days));
let month = (~opts=?, ()) => month(fakers, nullable(opts));
let weekday = (~opts=?, ()) => weekday(fakers, nullable(opts));
