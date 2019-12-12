let nullable = Faker.nullable;

type t = {
  account: Js.Nullable.t(int) => string,
  accountName: unit => string,
  amount:
    (
      Js.Nullable.t(int),
      Js.Nullable.t(int),
      Js.Nullable.t(int),
      Js.Nullable.t(string)
    ) =>
    string,
  bic: unit => string,
  bitcoinAddress: unit => string,
  currencyCode: unit => string,
  currencyName: unit => string,
  currencySymbol: unit => string,
  iban: unit => string,
  mask:
    (Js.Nullable.t(int), Js.Nullable.t(bool), Js.Nullable.t(bool)) => string,
  transactionType: unit => string,
};

[@bs.module "faker"] external fakers: t = "finance";

let account = (~length=?, ()) => fakers.account(nullable(length));
let accountName = () => fakers.accountName();
let amount = (~min=?, ~max=?, ~dec=?, ~symbol=?, ()) =>
  fakers.amount(
    nullable(min),
    nullable(max),
    nullable(dec),
    nullable(symbol),
  );
let bic = () => fakers.bic();
let bitcoinAddress = () => fakers.bitcoinAddress();
let currencyCode = () => fakers.currencyCode();
let currencyName = () => fakers.currencyName();
let currencySymbol = () => fakers.currencySymbol();
let iban = () => fakers.iban();
let mask = (~length=?, ~parens=?, ~ellipsis=?, ()) =>
  fakers.mask(nullable(length), nullable(parens), nullable(ellipsis));
let transactionType = () => fakers.transactionType();