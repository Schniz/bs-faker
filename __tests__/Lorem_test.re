open Jest;
open Expect;
open! Expect.Operators;

describe("BsFaker.Lorem", () => {
  test(".word", () =>
    expect(Js.typeof(Lorem.word())) === "string"
  );
  describe(".words", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Lorem.words())) === "string"
    );
    test("accepts wordCount", () =>
      expect(
        Lorem.words(~wordCount=3, ()) |> Js.String.split(" ") |> Js.Array.length,
      )
      === 3
    );
  });
  describe(".sentence", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Lorem.sentence())) === "string"
    );
    test("accepts wordCount", () =>
      expect(
        Lorem.sentence(~wordCount=3, ()) |> Js.String.split(" ") |> Js.Array.length,
      )
      === 3
    );
  });
  describe(".slug", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Lorem.slug())) === "string"
    );
    test("accepts wordCount", () =>
      expect(Lorem.slug(~wordCount=3, ()) |> Js.String.split("-") |> Js.Array.length)
      === 3
    );
  });
  describe(".sentences", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Lorem.sentences())) === "string"
    );
    test("accepts sentenceCount", () =>
      expect(
        Lorem.sentences(~sentenceCount=3, ())
        |> Js.String.split(".")
        |> Js.Array.length,
      )
      === 4
    ); /* because the last sentence also ends with a period */
    test("accepts separator", () =>
      expect(
        Lorem.sentences(~sentenceCount=3, ~separator=";;", ())
        |> Js.String.split(";;")
        |> Js.Array.length,
      )
      === 3
    );
  });
  describe("paragraph", () => {
    test("acepts optional args", () =>
      expect(Js.typeof(Lorem.paragraph())) === "string"
    );
    test("accepts sentenceCount", () =>
      expect(
        Lorem.paragraph(~sentenceCount=3, ())
        |> Js.String.split(".")
        |> Js.Array.length,
      )
      >= 4
    ); /* because the last sentence also ends with a period, but also paragraph inexplicably adds up to 3 additional sentences */
  });
  describe("paragraphs", () => {
    test("acepts optional args", () =>
      expect(Js.typeof(Lorem.paragraphs())) === "string"
    );
    test("accepts paragraphCount", () =>
      expect(
        Lorem.paragraphs(~paragraphCount=3, ())
        |> Js.String.split("\n \r")
        |> Js.Array.length,
      )
      === 3
    );
    test("accepts separator", () =>
      expect(
        Lorem.paragraphs(~paragraphCount=3, ~separator=";;;", ())
        |> Js.String.split(";;;")
        |> Js.Array.length,
      )
      === 3
    );
  });
  test("text", () =>
    expect(Js.typeof(Lorem.text())) === "string"
  );
  describe("lines", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(Lorem.lines())) === "string"
    );
    test("accepts lineCount", () =>
      expect(
        Lorem.lines(~lineCount=3, ()) |> Js.String.split("\n") |> Js.Array.length,
      )
      === 3
    );
  });
});
