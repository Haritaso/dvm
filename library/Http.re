let writer_callback = (a, b) => {
  Buffer.add_string(a, b);
  String.length(b);
};

let init_conn = url => {
  let buffer = Buffer.create(16384)
  and connection = Curl.init();
  Curl.set_timeout(connection, 1200);
  Curl.set_useragent(connection, "dvm");
  Curl.set_sslverifypeer(connection, false);
  Curl.set_sslverifyhost(connection, Curl.SSLVERIFYHOST_EXISTENCE);
  Curl.set_writefunction(connection, writer_callback(buffer));
  Curl.set_verbose(connection, false);
  Curl.set_post(connection, false);
  Curl.set_url(connection, url);
  (buffer, connection);
};

let get = url => {
  let (buffer, connection) = init_conn(url);
  Curl.set_followlocation(connection, true);
  Curl.perform(connection);
  Curl.cleanup(connection);
  Buffer.contents(buffer);
};