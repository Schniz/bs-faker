open Jest;
open Expect;
open! Expect.Operators;

describe("Faker.Name", () => {
  describe(".findName", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Faker.Name.findName())) === "string"
    );
    test("accepts firstName", () =>
      expect(Faker.Name.findName(~firstName="Gal", ())) |> toMatchRe(Js.Re.fromString("^Gal "))
    );
    test("accepts lastName", () =>
      expect(Faker.Name.findName(~lastName="Hagever", ())) |> toMatchRe(Js.Re.fromString(" Hagever$"))
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

describe("Faker.Lorem", () => {
  test(".word", () =>
    expect(Js.typeof(Faker.Lorem.word())) === "string"
  );
  describe(".words", () => {
    test("accepts optional args", () => {
      expect(Js.typeof(Faker.Lorem.words())) === "string"
    });
    test("accepts wordCount", () => {
      expect(
        Faker.Lorem.words(~wordCount=3, ())
        |> Js.String.split(" ")
        |> Js.Array.length
      ) === 3
    });
  });
  describe(".sentence", () => {
    test("accepts optional args", () => {
      expect(Js.typeof(Faker.Lorem.sentence())) === "string"
    });
    test("accepts wordCount", () => {
      expect(
        Faker.Lorem.sentence(~wordCount=3, ())
        |> Js.String.split(" ")
        |> Js.Array.length
      ) === 3
    });
  });
  describe(".slug", () => {
    test("accepts optional args", () => {
      expect(Js.typeof(Faker.Lorem.slug())) === "string"
    });
    test("accepts wordCount", () => {
      expect(
        Faker.Lorem.slug(~wordCount=3, ())
        |> Js.String.split("-")
        |> Js.Array.length
      ) === 3
    });
  });
  describe(".sentences", () => {
    test("accepts optional args", () => {
      expect(Js.typeof(Faker.Lorem.sentences())) === "string"
    });
    test("accepts sentenceCount", () => {
      expect(
        Faker.Lorem.sentences(~sentenceCount=3, ())
        |> Js.String.split(".")
        |> Js.Array.length
      ) === 4 /* because the last sentence also ends with a period */
    });
    test("accepts separator", () => {
      expect(
        Faker.Lorem.sentences(~sentenceCount=3, ~separator=";;", ())
        |> Js.String.split(";;")
        |> Js.Array.length
      ) === 3
    });
  });
  describe("paragraph", () => {
    test("acepts optional args", () => {
      expect(Js.typeof(Faker.Lorem.paragraph())) === "string"
    });
    test("accepts sentenceCount", () => {
      expect(
        Faker.Lorem.paragraph(~sentenceCount=3, ())
        |> Js.String.split(".")
        |> Js.Array.length
      ) >= 4 /* because the last sentence also ends with a period, but also paragraph inexplicably adds up to 3 additional sentences */
    });
  });
  describe("paragraphs", () => {
    test("acepts optional args", () => {
      expect(Js.typeof(Faker.Lorem.paragraphs())) === "string"
    });
    test("accepts paragraphCount", () => {
      expect(
        Faker.Lorem.paragraphs(~paragraphCount=3, ())
        |> Js.String.split("\n \r")
        |> Js.Array.length
      ) === 3
    });
    test("accepts separator", () => {
      expect(
        Faker.Lorem.paragraphs(~paragraphCount=3, ~separator=";;;", ())
        |> Js.String.split(";;;")
        |> Js.Array.length
      ) === 3
    });
  });
  test("text", () =>
    expect(Js.typeof(Faker.Lorem.text())) === "string"
  );
  describe("lines", () => {
    test("accepts optional args", () => {
      expect(Js.typeof(Faker.Lorem.lines())) === "string"
    });
    test("accepts lineCount", () => {
      expect(
        Faker.Lorem.lines(~lineCount=3, ())
        |> Js.String.split("\n")
        |> Js.Array.length
      ) === 3
    });
  });
});
