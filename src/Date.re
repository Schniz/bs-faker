type dateOption = {
  abbr: option(bool),
  context: option(bool),
};

type t = {
  past: (option(int), option(Js.Date.t)) => Js.Date.t,
  future: (option(int), option(Js.Date.t)) => Js.Date.t,
  between: (Js.Date.t, Js.Date.t) => Js.Date.t,
  recent: option(int) => Js.Date.t,
  month: dateOption => string,
  weekday: dateOption => string,
};
[@bs.module "faker"] external fakers: t = "date";
let past = (~years=?, ~refDate=?, ()) => fakers.past(years, refDate);
let future = (~years=?, ~refDate=?, ()) =>
  fakers.future((years), (refDate));
let between = (from, to_) => fakers.between(from, to_);
let recent = (~days=?, ()) => fakers.recent(days);
let month = (~abbr=?, ~context=?, ()) => fakers.month({abbr, context});
let weekday = (~abbr=?, ~context=?, ()) => fakers.weekday({abbr, context});