let nullable = Js.Nullable.fromOption;

module Image = {
  [@bs.deriving abstract]
  type t = {avatar: unit => string};
  [@bs.module "faker"] external fakers : t = "image";
  let avatar = () => avatar(fakers, ());
};

module Name = {
  [@bs.deriving abstract]
  type t = {
    findName: (Js.Nullable.t(string), Js.Nullable.t(string), Js.Nullable.t(string)) => string,
    firstName: Js.Nullable.t(string) => string,
    lastName: Js.Nullable.t(string) => string,
    prefix: Js.Nullable.t(string) => string,
    suffix: unit => string,
    title: unit => string,
    jobArea: unit => string,
    jobType: unit => string,
  };
  [@bs.module "faker"] external fakers : t = "name";
  let findName = (~firstName=?, ~lastName=?, ~gender=?, ()) =>
    findName(fakers, nullable(firstName), nullable(lastName), nullable(gender));
  let firstName = (~gender=?, ()) => firstName(fakers, nullable(gender));
  let lastName = (~gender=?, ()) => lastName(fakers, nullable(gender));
  let prefix = (~gender=?, ()) => prefix(fakers, nullable(gender));
  let suffix = () => suffix(fakers, ());
  let title = () => title(fakers, ());
  let jobArea = () => jobArea(fakers, ());
  let jobType = () => jobType(fakers, ());
};

module Internet = {
  [@bs.deriving abstract]
  type t = {userName: (Js.Nullable.t(string), Js.Nullable.t(string)) => string};
  [@bs.module "faker"] external fakers : t = "internet";
  let userName = (~firstName=?, ~lastName=?, ()) => userName(fakers, nullable(firstName), nullable(lastName));
};

module Lorem = {
  [@bs.deriving abstract]
  type t = {paragraph: unit => string};
  [@bs.module "faker"] external fakers : t = "lorem";
  let paragraph = () => paragraph(fakers, ());
};

module Date = {
  [@bs.deriving abstract]
  type t = {past: (Js.Nullable.t(int), Js.Nullable.t(Js.Date.t)) => Js.Date.t};
  [@bs.module "faker"] external fakers : t = "date";
  let past = (~years=?, ~refDate=?, ()) => past(fakers, nullable(years), nullable(refDate));
};
