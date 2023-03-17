<template>
  <div>
    <h1>
      BoardList
    </h1>
    <div>
      <router-link to="/board/1">1번으로가자</router-link>
    </div>
    <div>
      <router-link to="/board/2">2번으로가자</router-link>
    </div>
    <div>
      <router-link to="/board/3">3번으로가자</router-link>
    </div>
    <button @click="go789">dd</button>
  </div>
</template>

<script>
export default {
  methods:{
    go789(){
      this.$router.push("/board/789");
    }
  }
}
</script>

<style>

</style>