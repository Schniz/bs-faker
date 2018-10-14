open Jest;
open Expect;
open! Expect.Operators;

describe("BsFaker.System", () => {
  describe(".fileName", () =>
    test("accepts optional args", () =>
      expect(Js.typeof(System.fileName())) === "string"
    )
  );

  describe(".commonFileName", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(System.commonFileName())) === "string"
    );
    test("accepts ext", () =>
      expect(
        System.commonFileName(~ext="txt", ())
        |> Js.String.split(".")
        |> Array.get(_, 1),
      )
      === "txt"
    );
  });

  describe(".mimeType", () =>
    test("returns string", () =>
      expect(Js.typeof(System.mimeType())) === "string"
    )
  );

  describe(".commonFileType", () =>
    test("returns string", () =>
      expect(Js.typeof(System.commonFileType())) === "string"
    )
  );

  describe(".commonFileExt", () =>
    test("accepts optional args", () =>
      expect(Js.typeof(System.commonFileExt())) === "string"
    )
  );

  describe(".fileType", () =>
    test("returns string", () =>
      expect(Js.typeof(System.fileType())) === "string"
    )
  );

  describe(".fileExt", () => {
    test("accepts optional args", () =>
      expect(Js.typeof(System.fileExt())) === "string"
    );
    test("accepts mimeType", () =>
      expect(Js.typeof(System.fileExt(~mimeType="audio/webm", ()))) === "string"
    );
  });

  describe(".semver", () =>
    test("returns a semver string", () =>
      expect(System.semver()) |> toMatchRe(Js.Re.fromString("\\d\\.\\d\\.\\d"))
    )
  );
});
