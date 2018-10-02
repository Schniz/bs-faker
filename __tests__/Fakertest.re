open Jest;
open Expect;
open! Expect.Operators;

describe("Faker.fake", () => {
  test("returns ok(value) on success", () =>
    expect(
      Faker.fake("Hello {{name.firstName}}")
      |. Belt.Result.getWithDefault("error"),
    )
    |> toMatchRe(Js.Re.fromString("^Hello \\w+$"))
  );

  test("returns error(message) on error", () =>
    expect(
      Faker.fake("Hello {{shouldn't work}}")
      |. Belt.Result.getWithDefault("error"),
    )
    === "error"
  );
});

describe("Faker.Name", () => {
  describe(".findName", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Faker.Name.findName())) === "string"
    );
    test("accepts firstName", () =>
      expect(Faker.Name.findName(~firstName="Gal", ()))
      |> toMatchRe(Js.Re.fromString("Gal "))
    );
    test("accepts lastName", () =>
      expect(Faker.Name.findName(~lastName="Hagever", ()))
      |> toMatchRe(Js.Re.fromString(" Hagever"))
    );
  });

  test(".firstName", () =>
    expect(Js.typeof(Faker.Name.firstName())) === "string"
  );
  test(".lastName", () =>
    expect(Js.typeof(Faker.Name.lastName())) === "string"
  );
  test(".prefix", () =>
    expect(Js.typeof(Faker.Name.prefix())) === "string"
  );
  test(".suffix", () =>
    expect(Js.typeof(Faker.Name.suffix())) === "string"
  );
  test(".title", () =>
    expect(Js.typeof(Faker.Name.title())) === "string"
  );
  test(".jobArea", () =>
    expect(Js.typeof(Faker.Name.jobArea())) === "string"
  );
  test(".jobType", () =>
    expect(Js.typeof(Faker.Name.jobType())) === "string"
  );
});

describe("Faker.Image", () => {
  test(".avatar", () =>
    expect(Js.typeof(Faker.Image.avatar())) === "string"
  );
  test(".abstract", () =>
    expect(Js.typeof(Faker.Image.abstract())) === "string"
  );
  test(".animals", () =>
    expect(Js.typeof(Faker.Image.animals())) === "string"
  );
  test(".business", () =>
    expect(Js.typeof(Faker.Image.business())) === "string"
  );
  test(".cats", () =>
    expect(Js.typeof(Faker.Image.cats())) === "string"
  );
  test(".city", () =>
    expect(Js.typeof(Faker.Image.city())) === "string"
  );
  test(".dataUri", () =>
    expect(Js.typeof(Faker.Image.dataUri())) === "string"
  );
  test(".fashion", () =>
    expect(Js.typeof(Faker.Image.fashion())) === "string"
  );
  test(".food", () =>
    expect(Js.typeof(Faker.Image.food())) === "string"
  );
  test(".image", () =>
    expect(Js.typeof(Faker.Image.image())) === "string"
  );
  test(".imageUrl", () =>
    expect(Js.typeof(Faker.Image.imageUrl())) === "string"
  );
  test(".natrue", () =>
    expect(Js.typeof(Faker.Image.nature())) === "string"
  );
  test(".nightlife", () =>
    expect(Js.typeof(Faker.Image.nightlife())) === "string"
  );
  test(".people", () =>
    expect(Js.typeof(Faker.Image.people())) === "string"
  );
  test(".sports", () =>
    expect(Js.typeof(Faker.Image.sports())) === "string"
  );
  test(".technics", () =>
    expect(Js.typeof(Faker.Image.technics())) === "string"
  );
  test(".transport  ", () =>
    expect(Js.typeof(Faker.Image.transport())) === "string"
  );
});
