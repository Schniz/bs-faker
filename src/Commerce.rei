let color: unit => string;
let department: unit => string;
let productName: unit => string;
let price:
  (~min: int=?, ~max: int=?, ~decimal: int=?, ~symbol: string=?, unit) =>
  string;
let productAdjective: unit => string;
let productMaterial: unit => string;
let product: unit => string;
