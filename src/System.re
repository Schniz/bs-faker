type t = {
  fileName: (option(string), option(string)) => string,
  commonFileName: (option(string), option(string)) => string,
  mimeType: unit => string,
  commonFileType: unit => string,
  commonFileExt: option(string) => string,
  fileType: unit => string,
  fileExt: option(string) => string,
  semver: unit => string,
};

[@bs.module "faker"] external fakers: t = "system";

/*
   Optional ext and type arguments are ignored by faker.js.
   See https://github.com/Marak/faker.js/issues/687
   Therefore they are not tested.
 */
let fileName = (~ext=?, ~type_=?, ()) => fakers.fileName(ext, type_);

/*
   Optional type argument is ignored by faker.js.
   See https://github.com/Marak/faker.js/issues/687
   Therefore it is not tested.
 */
let commonFileName = (~ext=?, ~type_=?, ()) =>
  fakers.commonFileName(ext, type_);
let mimeType = () => fakers.mimeType();
let commonFileType = () => fakers.commonFileType();

/*
   Optional type argument is ignored by faker.js.
   Therefore it is not tested.
 */
let commonFileExt = (~type_=?, ()) => fakers.commonFileExt(type_);
let fileType = () => fakers.fileType();
let fileExt = (~mimeType=?, ()) => fakers.fileExt(mimeType);
let semver = () => fakers.semver();