let nullable = Faker.nullable;

type t = {
  userName: (Js.Nullable.t(string), Js.Nullable.t(string)) => string,
  avatar: unit => string,
  email:
    (Js.Nullable.t(string), Js.Nullable.t(string), Js.Nullable.t(string)) =>
    string,
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

[@bs.module "faker"] external fakers: t = "internet";
let userName = (~firstName=?, ~lastName=?, ()) =>
  fakers.userName(nullable(firstName), nullable(lastName));
let avatar = () => fakers.avatar();
let email = (~firstName=?, ~lastName=?, ~provider=?, ()) =>
  fakers.email(
    nullable(firstName),
    nullable(lastName),
    nullable(provider),
  );
let exampleEmail = (~firstName=?, ~lastName=?, ()) =>
  fakers.exampleEmail(nullable(firstName), nullable(lastName));
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
    nullable(length),
    nullable(memorable),
    nullable(pattern),
    nullable(prefix),
  );
