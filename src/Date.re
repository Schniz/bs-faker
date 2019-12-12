let nullable = Faker.nullable;

type dateOption = {
  .
  "abbr": Js.Nullable.t(bool),
  "context": Js.Nullable.t(bool),
};

type t = {
  past: (Js.Nullable.t(int), Js.Nullable.t(Js.Date.t)) => Js.Date.t,
  future: (Js.Nullable.t(int), Js.Nullable.t(Js.Date.t)) => Js.Date.t,
  between: (Js.Date.t, Js.Date.t) => Js.Date.t,
  recent: Js.Nullable.t(int) => Js.Date.t,
  month: dateOption => string,
  weekday: dateOption => string,
};
[@bs.module "faker"] external fakers: t = "date";
let past = (~years=?, ~refDate=?, ()) =>
  fakers.past(nullable(years), nullable(refDate));
let future = (~years=?, ~refDate=?, ()) =>
  fakers.future(nullable(years), nullable(refDate));
let between = (from, to_) => fakers.between(from, to_);
let recent = (~days=?, ()) => fakers.recent(nullable(days));
let month = (~abbr=?, ~context=?, ()) =>
  fakers.month({"abbr": nullable(abbr), "context": nullable(context)});
let weekday = (~abbr=?, ~context=?, ()) =>
  fakers.weekday({"abbr": nullable(abbr), "context": nullable(context)});