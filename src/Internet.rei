let userName: (~firstName: string=?, ~lastName: string=?, unit) => string;
let avatar: unit => string;
let email:
  (~firstName: string=?, ~lastName: string=?, ~provider: string=?, unit) => string;
let exampleEmail: (~firstName: string=?, ~lastName: string=?, unit) => string;
let protocol: unit => string;
let url: unit => string;
let domainName: unit => string;
let domainSuffix: unit => string;
let domainWord: unit => string;
let ip: unit => string;
let ipv6: unit => string;
let userAgent: unit => string;
let color: (~red: int=?, ~green: int=?, ~blue: int=?, unit) => string;
let mac: unit => string;
let password:
  (~length: int=?, ~memorable: bool=?, ~pattern: Js.Re.t=?, ~prefix: string=?, unit) =>
  string;
