redo-ifchange all

if ./ptable 2>&1 >/dev/null | grep 'Done'; then
  echo 'success'
  exit 0
else
  echo 'missing Done'
  exit 1
fi
