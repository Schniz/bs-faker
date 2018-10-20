let nullable = Faker.nullable;

[@bs.deriving abstract]
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

[@bs.module "faker"] external fakers : t = "finance";

let account = (~length=?, ()) => account(fakers, nullable(length));
let accountName = () => accountName(fakers, ());
let amount = (~min=?, ~max=?, ~dec=?, ~symbol=?, ()) =>
  amount(
    fakers,
    nullable(min),
    nullable(max),
    nullable(dec),
    nullable(symbol),
  );
let bic = () => bic(fakers, ());
let bitcoinAddress = () => bitcoinAddress(fakers, ());
let currencyCode = () => currencyCode(fakers, ());
let currencyName = () => currencyName(fakers, ());
let currencySymbol = () => currencySymbol(fakers, ());
let iban = () => iban(fakers, ());
let mask = (~length=?, ~parens=?, ~ellipsis=?, ()) =>
  mask(fakers, nullable(length), nullable(parens), nullable(ellipsis));
let transactionType = () => transactionType(fakers, ());