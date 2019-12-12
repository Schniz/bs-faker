let nullable = Faker.nullable;


type t = {
  fileName: (Js.Nullable.t(string), Js.Nullable.t(string)) => string,
  commonFileName: (Js.Nullable.t(string), Js.Nullable.t(string)) => string,
  mimeType: unit => string,
  commonFileType: unit => string,
  commonFileExt: Js.Nullable.t(string) => string,
  fileType: unit => string,
  fileExt: Js.Nullable.t(string) => string,
  semver: unit => string,
};

[@bs.module "faker"] external fakers : t = "system";

/*
   Optional ext and type arguments are ignored by faker.js.
   See https://github.com/Marak/faker.js/issues/687
   Therefore they are not tested.
 */
let fileName = (~ext=?, ~type_=?, ()) =>
  fakers.fileName( nullable(ext), nullable(type_));

/*
   Optional type argument is ignored by faker.js.
   See https://github.com/Marak/faker.js/issues/687
   Therefore it is not tested.
 */
let commonFileName = (~ext=?, ~type_=?, ()) =>
  fakers.commonFileName( nullable(ext), nullable(type_));
let mimeType = () => fakers.mimeType( ());
let commonFileType = () => fakers.commonFileType( ());

/*
   Optional type argument is ignored by faker.js.
   Therefore it is not tested.
 */
let commonFileExt = (~type_=?, ()) => fakers.commonFileExt( nullable(type_));
let fileType = () => fakers.fileType( ());
let fileExt = (~mimeType=?, ()) => fakers.fileExt( nullable(mimeType));
let semver = () => fakers.semver( ());
