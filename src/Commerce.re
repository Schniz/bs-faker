
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

let color = () => fakers.color(());
let department = () => fakers.department(());
let productName = () => fakers.productName(());
let price = (~min=0, ~max=1000, ~decimal=2, ~symbol="", ()) =>
  fakers.price(min, max, decimal, symbol);
let productAdjective = () => fakers.productAdjective(());
let productMaterial = () => fakers.productMaterial(());
let product = () => fakers.product(());
