#!/bin/bash

FZF_OPTS="--height 25% --border --reverse"

VERSION=$(helmenv versions | grep -oE '[0-9]+\.[0-9]+\.[0-9]+'| fzf $FZF_OPTS --prompt="VERSION > ")
if [ -z "$VERSION" ]; then
  echo "No version was selected." && exit 0
fi
CMD="helmenv global $VERSION"
echo $CMD && eval $CMD

VERSION_MAJOR=$(echo $VERSION | cut -d '.' -f1)

if [ "$VERSION_MAJOR" -eq 3 ]; then
  SELECTED=$(helm list --all-namespaces | awk '{print $1 " (" $2 ")"}' | fzf $FZF_OPTS --header-lines=1 --prompt="VERSION: $VERSION > CHART > ")
  CHART=$(echo $SELECTED | awk '{print $1}')
  NAMESPACE=$(echo $SELECTED | awk '{print $2}' | tr -d '()')
fi
if [ "$VERSION_MAJOR" -eq 2 ]; then
  CHART=$(helm list | awk '{print $1}' | fzf $FZF_OPTS --header-lines=1 --prompt="VERSION: $VERSION > CHART > ")
fi
if [ -z "$CHART" ]; then
  echo "No chart was selected." && exit 0
fi

ACTION=$(echo -e "DELETE" | fzf $FZF_OPTS --prompt="VERSION: $VERSION > CHART: $CHART > ACTION > ")
if [ "$ACTION" == "DELETE" ]; then
  echo "You are about to execute the following command to delete the chart:"
  if [ "$VERSION_MAJOR" -eq 2 ]; then
    CMD="helm delete --purge $CHART"
  elif [ "$VERSION_MAJOR" -eq 3 ]; then
    CMD="helm delete $CHART --namespace=$NAMESPACE"
  fi
  echo "$CMD"
  CONFIRM=$(echo -e "NO\nYES" | fzf $FZF_OPTS --prompt="Are you sure? (y/N) > ")
  if [ "$CONFIRM" == "YES" ]; then
    eval $CMD
  else
    echo "Deletion cancelled." && exit 0
  fi
else
  echo "No action was selected." && exit 0
fi