let nullable = Faker.nullable;


type t = {
  phoneNumber: Js.Nullable.t(string) => string,
  phoneNumberFormat: int => string,
  phoneFormats: unit => string,
};
[@bs.module "faker"] external fakers : t = "phone";
let phoneNumber = (~format=?, ()) => fakers.phoneNumber( nullable(format));
let phoneNumberFormat = (~phoneFormatsIndex) =>
  fakers.phoneNumberFormat( phoneFormatsIndex);
let phoneFormats = () => fakers.phoneFormats( ());
