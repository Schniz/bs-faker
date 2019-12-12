let nullable = Faker.nullable;

type t = {
  findName:
    (Js.Nullable.t(string), Js.Nullable.t(string), Js.Nullable.t(string)) =>
    string,
  firstName: Js.Nullable.t(string) => string,
  lastName: Js.Nullable.t(string) => string,
  prefix: Js.Nullable.t(string) => string,
  suffix: unit => string,
  title: unit => string,
  jobArea: unit => string,
  jobType: unit => string,
};
[@bs.module "faker"] external fakers: t = "name";

let findName = (~firstName=?, ~lastName=?, ~gender=?, ()) =>
  fakers.findName(
    nullable(firstName),
    nullable(lastName),
    nullable(gender),
  );
let firstName = (~gender=?, ()) => fakers.firstName(nullable(gender));
let lastName = (~gender=?, ()) => fakers.lastName(nullable(gender));
let prefix = (~gender=?, ()) => fakers.prefix(nullable(gender));
let suffix = () => fakers.suffix();
let title = () => fakers.title();
let jobArea = () => fakers.jobArea();
let jobType = () => fakers.jobType();
