type t = {
  findName:
    (option(string), option(string), option(string)) =>
    string,
  firstName: option(string) => string,
  lastName: option(string) => string,
  prefix: option(string) => string,
  suffix: unit => string,
  title: unit => string,
  jobArea: unit => string,
  jobType: unit => string,
};
[@bs.module "faker"] external fakers: t = "name";

let findName = (~firstName=?, ~lastName=?, ~gender=?, ()) =>
  fakers.findName(
    (firstName),
    (lastName),
    (gender),
  );
let firstName = (~gender=?, ()) => fakers.firstName((gender));
let lastName = (~gender=?, ()) => fakers.lastName((gender));
let prefix = (~gender=?, ()) => fakers.prefix((gender));
let suffix = () => fakers.suffix();
let title = () => fakers.title();
let jobArea = () => fakers.jobArea();
let jobType = () => fakers.jobType();
