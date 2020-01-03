/*
 Copyright 2019-2020 BSKY
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

let decorateString = version =>
  <Pastel> <Pastel color=Pastel.Cyan> "* " </Pastel> version </Pastel>;

let run = () => {
  if (!Sys.file_exists(Constant.installDir)) {
    Core.Unix.mkdir_p(Constant.installDir);
  };

  Core.Sys.ls_dir(Constant.installDir)
  |> List.rev
  |> List.iter(ver => ver |> decorateString |> Console.log);
};
