module Image: {let avatar: unit => string;};
module Name: {
  let findName: (~firstName: string=?, ~lastName: string=?, ~gender: string=?, unit) => string;
  let firstName: (~gender: string=?, unit) => string;
  let lastName: (~gender: string=?, unit) => string;
  let prefix: (~gender: string=?, unit) => string;
  let suffix: unit => string;
  let title: unit => string;
  let jobArea: unit => string;
  let jobType: unit => string;
};
module Internet: {let userName: (~firstName: string=?, ~lastName: string=?, unit) => string;};
module Lorem: {let paragraph: unit => string;};
module Date: {let past: (~years: int=?, ~refDate: Js.Date.t=?, unit) => Js.Date.t;};
