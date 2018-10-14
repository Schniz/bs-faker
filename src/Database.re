[@bs.deriving abstract]
type t = {
  column: unit => string,
  type_: unit => string,
  collation: unit => string,
  engine: unit => string,
};
[@bs.module "faker"] external fakers : t = "database";
let column = () => column(fakers, ());
[@bs.module "faker"] [@bs.scope "database"] [@bs.val]
external type_ : unit => string = "type";
let type_ = () => type_();
let collation = () => collation(fakers, ());
let engine = () => engine(fakers, ());
