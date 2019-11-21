open Dvm;

let createDownloadUrl = version =>
  "https://github.com/denoland/deno/releases/download/v"
  ++ version
  ++ "/deno_"
  ++ System.os
  ++ "_"
  ++ System.arch
  ++ ".gz";

let run = version => {
  let downloadUrl = createDownloadUrl(version);
  let installVersionDir = Filename.concat(Constant.installDir, version);
  let binaryPath = Filename.concat(installVersionDir, "deno");

  if (!Sys.file_exists(Constant.dvmDir)) {
    Core.Unix.mkdir_p(Constant.dvmDir);
  };

  if (Sys.file_exists(installVersionDir)) {
    Console.log(
      <Pastel>
        "Deno runtime version "
        <Pastel color=Pastel.Red underline=true> version </Pastel>
        " is already installed."
      </Pastel>,
    );
    exit(1);
  };

  Core.Unix.mkdir_p(installVersionDir);
  Core_kernel.Out_channel.write_all(
    binaryPath,
    ~data=Rresult.R.get_ok(Http.Curl.get(downloadUrl) |> Ezgzip.decompress),
  );

  Core.Unix.chmod(binaryPath, ~perm=755);

  Console.log(
    <Pastel>
      "Deno runtime version "
      <Pastel color=Pastel.Cyan underline=true> version </Pastel>
      " was successfully installed!"
    </Pastel>,
  );
};
