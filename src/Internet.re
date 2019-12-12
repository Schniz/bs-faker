type t = {
  userName: (option(string), option(string)) => string,
  avatar: unit => string,
  email:
    (option(string), option(string), option(string)) =>
    string,
  exampleEmail: (option(string), option(string)) => string,
  protocol: unit => string,
  url: unit => string,
  domainName: unit => string,
  domainSuffix: unit => string,
  domainWord: unit => string,
  ip: unit => string,
  ipv6: unit => string,
  userAgent: unit => string,
  color: (int, int, int) => string,
  mac: unit => string,
  password:
    (
      option(int),
      option(bool),
      option(Js.Re.t),
      option(string)
    ) =>
    string,
};

[@bs.module "faker"] external fakers: t = "internet";
let userName = (~firstName=?, ~lastName=?, ()) =>
  fakers.userName((firstName), (lastName));
let avatar = () => fakers.avatar();
let email = (~firstName=?, ~lastName=?, ~provider=?, ()) =>
  fakers.email(
    (firstName),
    (lastName),
    (provider),
  );
let exampleEmail = (~firstName=?, ~lastName=?, ()) =>
  fakers.exampleEmail((firstName), (lastName));
let protocol = () => fakers.protocol();
let url = () => fakers.url();
let domainName = () => fakers.domainName();
let domainSuffix = () => fakers.domainSuffix();
let domainWord = () => fakers.domainWord();
let ip = () => fakers.ip();
let ipv6 = () => fakers.ipv6();
let userAgent = () => fakers.userAgent();
let color = (~red=0, ~green=0, ~blue=0, ()) =>
  fakers.color(red, green, blue);
let mac = () => fakers.mac();
let password = (~length=?, ~memorable=?, ~pattern=?, ~prefix=?, ()) =>
  fakers.password(
    (length),
    (memorable),
    (pattern),
    (prefix),
  );
