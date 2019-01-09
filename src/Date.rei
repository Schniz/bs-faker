type dateOption = {
  .
  "abbr": bool,
  "context": bool,
};
let past: (~years: int=?, ~refDate: Js.Date.t=?, unit) => Js.Date.t;
let future: (~years: int=?, ~refDate: Js.Date.t=?, unit) => Js.Date.t;
let between: (Js.Date.t, Js.Date.t) => Js.Date.t;
let recent: (~days: int=?, unit) => Js.Date.t;
let month: (~opts: dateOption=?, unit) => string;
let weekday: (~opts: dateOption=?, unit) => string;
