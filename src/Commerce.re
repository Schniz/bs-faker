[@bs.deriving abstract]
type t = {
  color: unit => string,
  department: unit => string,
  productName: unit => string,
  price: (int, int, int, string) => string,
  productAdjective: unit => string,
  productMaterial: unit => string,
  product: unit => string,
};

[@bs.module "faker"] external fakers : t = "commerce";

let color = () => color(fakers, ());
let department = () => department(fakers, ());
let productName = () => productName(fakers, ());
let price = (~min=0, ~max=1000, ~decimal=2, ~symbol="", ()) =>
  price(fakers, min, max, decimal, symbol);
let productAdjective = () => productAdjective(fakers, ());
let productMaterial = () => productMaterial(fakers, ());
let product = () => product(fakers, ());
