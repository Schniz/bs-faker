type locale =
  | Az
  | Cz
  | De
  | De_AT
  | De_CH
  | En
  | En_AU
  | En_BORK
  | En_CA
  | En_GB
  | En_IE
  | En_IND
  | En_US
  | En_au_ocker
  | Es
  | Es_MX
  | Fa
  | Fr
  | Fr_CA
  | Ge
  | Id_ID
  | It
  | Ja
  | Ko
  | Nb_NO
  | Nep
  | Nl
  | Pl
  | Pt_BR
  | Ru
  | Sk
  | Sv
  | Tr
  | Uk
  | Vi
  | Zh_CN
  | Zh_TW;

type t = {mutable locale: string};

[@bs.module] external faker: t = "faker";

let getLocale = () => faker.locale;

let string_from_locale =
  fun
  | Az => "az"
  | Cz => "cz"
  | De => "de"
  | De_AT => "de_AT"
  | De_CH => "de_CH"
  | En => "en"
  | En_AU => "en_AU"
  | En_BORK => "en_BORK"
  | En_CA => "en_CA"
  | En_GB => "en_GB"
  | En_IE => "en_IE"
  | En_IND => "en_IND"
  | En_US => "en_US"
  | En_au_ocker => "en_au_ocker"
  | Es => "es"
  | Es_MX => "es_MX"
  | Fa => "fa"
  | Fr => "fr"
  | Fr_CA => "fr_CA"
  | Ge => "ge"
  | Id_ID => "id_ID"
  | It => "it"
  | Ja => "ja"
  | Ko => "ko"
  | Nb_NO => "nb_NO"
  | Nep => "nep"
  | Nl => "nl"
  | Pl => "pl"
  | Pt_BR => "pt_BR"
  | Ru => "ru"
  | Sk => "sk"
  | Sv => "sv"
  | Tr => "tr"
  | Uk => "uk"
  | Vi => "vi"
  | Zh_CN => "zh_CN"
  | Zh_TW => "zh_TW";

let setLocale = locale => {
  let locale_string = string_from_locale(locale);
  faker.locale = locale_string;
};