let nullable = Faker.nullable;

[@bs.deriving abstract]
type t = {
  userName: (Js.Nullable.t(string), Js.Nullable.t(string)) => string,
  avatar: unit => string,
  email:
    (Js.Nullable.t(string), Js.Nullable.t(string), Js.Nullable.t(string)) => string,
  exampleEmail: (Js.Nullable.t(string), Js.Nullable.t(string)) => string,
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
      Js.Nullable.t(int),
      Js.Nullable.t(bool),
      Js.Nullable.t(Js.Re.t),
      Js.Nullable.t(string)
    ) =>
    string,
};

[@bs.module "faker"] external fakers : t = "internet";
let userName = (~firstName=?, ~lastName=?, ()) =>
  userName(fakers, nullable(firstName), nullable(lastName));
let avatar = () => avatar(fakers, ());
let email = (~firstName=?, ~lastName=?, ~provider=?, ()) =>
  email(fakers, nullable(firstName), nullable(lastName), nullable(provider));
let exampleEmail = (~firstName=?, ~lastName=?, ()) =>
  exampleEmail(fakers, nullable(firstName), nullable(lastName));
let protocol = () => protocol(fakers, ());
let url = () => url(fakers, ());
let domainName = () => domainName(fakers, ());
let domainSuffix = () => domainSuffix(fakers, ());
let domainWord = () => domainWord(fakers, ());
let ip = () => ip(fakers, ());
let ipv6 = () => ipv6(fakers, ());
let userAgent = () => userAgent(fakers, ());
let color = (~red=0, ~green=0, ~blue=0, ()) => color(fakers, red, green, blue);
let mac = () => mac(fakers, ());
let password = (~length=?, ~memorable=?, ~pattern=?, ~prefix=?, ()) =>
  password(
    fakers,
    nullable(length),
    nullable(memorable),
    nullable(pattern),
    nullable(prefix),
  );
