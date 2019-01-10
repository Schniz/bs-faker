let past: (~years: int=?, ~refDate: Js.Date.t=?, unit) => Js.Date.t;
let future: (~years: int=?, ~refDate: Js.Date.t=?, unit) => Js.Date.t;
let between: (Js.Date.t, Js.Date.t) => Js.Date.t;
let recent: (~days: int=?, unit) => Js.Date.t;
let month: (~abbr: bool=?, ~context: bool=?, unit) => string;
let weekday: (~abbr: bool=?, ~context: bool=?, unit) => string;
