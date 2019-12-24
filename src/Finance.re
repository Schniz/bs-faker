type t = {
  account: option(int) => string,
  accountName: unit => string,
  amount:
    (option(int), option(int), option(int), option(string)) => string,
  bic: unit => string,
  bitcoinAddress: unit => string,
  currencyCode: unit => string,
  currencyName: unit => string,
  currencySymbol: unit => string,
  iban: unit => string,
  mask: (option(int), option(bool), option(bool)) => string,
  transactionType: unit => string,
};

[@bs.module "faker"] external fakers: t = "finance";

let account = (~length=?, ()) => fakers.account(length);
let accountName = () => fakers.accountName();
let amount = (~min=?, ~max=?, ~dec=?, ~symbol=?, ()) =>
  fakers.amount(min, max, dec, symbol);
let bic = () => fakers.bic();
let bitcoinAddress = () => fakers.bitcoinAddress();
let currencyCode = () => fakers.currencyCode();
let currencyName = () => fakers.currencyName();
let currencySymbol = () => fakers.currencySymbol();
let iban = () => fakers.iban();
let mask = (~length=?, ~parens=?, ~ellipsis=?, ()) =>
  fakers.mask(length, parens, ellipsis);
let transactionType = () => fakers.transactionType();
