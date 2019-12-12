type t = {
  column: unit => string,
  [@bs.as "type"]
  type_: unit => string,
  collation: unit => string,
  engine: unit => string,
};
[@bs.module "faker"] external fakers: t = "database";
let column = () => fakers.column();
let type_ = () => fakers.type_();
let collation = () => fakers.collation();
let engine = () => fakers.engine();
