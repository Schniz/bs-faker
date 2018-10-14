let nullable = Faker.nullable;

[@bs.deriving abstract]
type t = {
  findName:
    (Js.Nullable.t(string), Js.Nullable.t(string), Js.Nullable.t(string)) => string,
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
