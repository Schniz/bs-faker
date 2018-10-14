let nullable = Faker.nullable;

[@bs.deriving abstract]
type t = {
  phoneNumber: Js.Nullable.t(string) => string,
  phoneNumberFormat: int => string,
  phoneFormats: unit => string,
};
[@bs.module "faker"] external fakers : t = "phone";
let phoneNumber = (~format=?, ()) => phoneNumber(fakers, nullable(format));
let phoneNumberFormat = (~phoneFormatsIndex) =>
  phoneNumberFormat(fakers, phoneFormatsIndex);
let phoneFormats = () => phoneFormats(fakers, ());
