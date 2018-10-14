let nullable = Faker.nullable;

type fetchImage_js =
  (Js.Nullable.t(int), Js.Nullable.t(int), Js.Nullable.t(bool)) => string;

[@bs.deriving abstract]
type t = {
  avatar: unit => string,
  abstract: fetchImage_js,
  animals: fetchImage_js,
  business: fetchImage_js,
  cats: fetchImage_js,
  city: fetchImage_js,
  dataUri: (Js.Nullable.t(int), Js.Nullable.t(int)) => string,
  fashion: fetchImage_js,
  food: fetchImage_js,
  image: fetchImage_js,
  imageUrl:
    (
      Js.Nullable.t(int),
      Js.Nullable.t(int),
      Js.Nullable.t(string),
      Js.Nullable.t(bool),
      unit
    ) =>
    string,
  nature: fetchImage_js,
  nightlife: fetchImage_js,
  people: fetchImage_js,
  sports: fetchImage_js,
  technics: fetchImage_js,
  transport: fetchImage_js,
};

[@bs.module "faker"] external fakers : t = "image";

let fetchImage = (fn, ~width=?, ~height=?, ~randomize=?, ()) =>
  fn(fakers, nullable(width), nullable(height), nullable(randomize));
let avatar = () => avatar(fakers, ());
let dataUri = (~width=?, ~height=?, ()) =>
  dataUri(fakers, nullable(width), nullable(height));
let imageUrl = (~width=?, ~height=?, ~category=?, ~randomize=?, ()) =>
  imageUrl(
    fakers,
    nullable(width),
    nullable(height),
    nullable(category),
    nullable(randomize),
    (),
  );
let abstract = fetchImage(abstract);
let animals = fetchImage(animals);
let business = fetchImage(business);
let cats = fetchImage(cats);
let city = fetchImage(city);
let fashion = fetchImage(fashion);
let food = fetchImage(food);
let image = fetchImage(image);
let nature = fetchImage(nature);
let nightlife = fetchImage(nightlife);
let people = fetchImage(people);
let sports = fetchImage(sports);
let technics = fetchImage(technics);
let transport = fetchImage(transport);
