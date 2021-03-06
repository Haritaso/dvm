module Commands = {
  let gc = () => Gc.run();
  let init = shell => Init.run(shell);
  let install = version => Install.run(version);
  let latest = () => Latest.run();
  let ls_remote = () => Ls_remote.run();
  let ls = () => Ls.run();
  let uninstall = version => Uninstall.run(version);
  let use = version => Use.run(version);
};

let default = {
  let doc = Package_info.description;
  let man = [`S(Cmdliner.Manpage.s_bugs), `P(Package_info.issueTracker)];
  let version = Package_info.version;

  Cmdliner.Term.(
    ret(const(_ => `Help((`Pager, None))) $ const()),
    info(Package_info.name, ~doc, ~man, ~version),
  );
};

let gc = {
  let doc = "Purge unused versions of the Deno runtime.";

  Cmdliner.Term.(app(const(Commands.gc), const()), info("gc", ~doc));
};

let init = {
  let doc = "Print the path to the Deno runtime.";

  Cmdliner.Term.(
    const(Commands.init)
    $ Cmdliner.Arg.(required & pos(0, some(string), None) & info([])),
    info("init", ~doc),
  );
};

let install = {
  let doc = "Install a specific version of the Deno runtime.";
  let argDoc = "Specify the version to install in $(docv).";
  let argDocv = "VERSION";

  Cmdliner.Term.(
    const(Commands.install)
    $ Cmdliner.Arg.(
        required
        & pos(0, some(string), None)
        & info([], ~doc=argDoc, ~docv=argDocv)
      ),
    info("install", ~doc),
  );
};

let latest = {
  let doc = "Install the latest version of the Deno runtime.";

  Cmdliner.Term.(
    app(const(Commands.latest), const()),
    info("latest", ~doc),
  );
};

let ls_remote = {
  let doc = "List all remote versions of the Deno runtime.";

  Cmdliner.Term.(
    app(const(Commands.ls_remote), const()),
    info("ls-remote", ~doc),
  );
};

let ls = {
  let doc = "List installed versions of the Deno runtime.";

  Cmdliner.Term.(app(const(Commands.ls), const()), info("ls", ~doc));
};

let uninstall = {
  let doc = "Uninstall a specific version of the Deno runtime.";
  let argDoc = "Specify the version to uninstall in $(docv).";
  let argDocv = "VERSION";

  Cmdliner.Term.(
    const(Commands.uninstall)
    $ Cmdliner.Arg.(
        required
        & pos(0, some(string), None)
        & info([], ~doc=argDoc, ~docv=argDocv)
      ),
    info("uninstall", ~doc),
  );
};

let use = {
  let doc = "Set the Deno runtime version.";
  let argDoc = "Specify the version to use in $(docv).";
  let argDocv = "VERSION";

  Cmdliner.Term.(
    const(Commands.use)
    $ Cmdliner.Arg.(
        required
        & pos(0, some(string), None)
        & info([], ~doc=argDoc, ~docv=argDocv)
      ),
    info("use", ~doc),
  );
};

let () =
  Cmdliner.Term.eval_choice(
    default,
    [gc, init, install, latest, ls_remote, ls, uninstall, use],
  )
  |> Cmdliner.Term.exit;
