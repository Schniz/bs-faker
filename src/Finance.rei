let account: (~length: int=?, unit) => string;
let accountName: unit => string;
let amount:
  (~min: int=?, ~max: int=?, ~dec: int=?, ~symbol: string=?, unit) => string;
let bic: unit => string;
let bitcoinAddress: unit => string;
let currencyCode: unit => string;
let currencyName: unit => string;
let currencySymbol: unit => string;
let iban: unit => string;
let mask: (~length: int=?, ~parens: bool=?, ~ellipsis: bool=?, unit) => string;
let transactionType: unit => string;