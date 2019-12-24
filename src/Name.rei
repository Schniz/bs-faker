let findName:
  (~firstName: string=?, ~lastName: string=?, ~gender: string=?, unit) =>
  string;
let firstName: (~gender: string=?, unit) => string;
let lastName: (~gender: string=?, unit) => string;
let prefix: (~gender: string=?, unit) => string;
let suffix: unit => string;
let title: unit => string;
let jobArea: unit => string;
let jobType: unit => string;
